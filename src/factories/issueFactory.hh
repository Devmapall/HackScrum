<?hh //strict

require_once Config::ROOT."abstract/scrumElementFactory.hh";
require_once Config::ROOT."gateways/issueGateway.hh";
require_once Config::ROOT."issue.hh";
require_once Config::ROOT."enum/severity.hh";
require_once Config::ROOT."enum/priority.hh";
require_once Config::ROOT."enum/status.hh";

class IssueFactory extends ScrumElementFactory {

    private UserFactory $ufac;

    public function __construct() {
        $this->gate = new IssueGateway();
        $this->ufac = new UserFactory();
    }
    
    public function createAll(): Vector<ScrumElement> {
        //UNSAFE
        $vec = $this->gate->getAll();
        $ret = Vector{};
        
        foreach($vec as $val) {
            $obj = new Issue();
            $obj->setID((int)$val->ID);
            $obj->setTitle($val->title);
            $obj->setText($val->text);
            $obj->setSeverity(Severity::assert((int)$val->severity));
            $obj->setPriority(Priority::assert((int)$val->priority));
            $obj->setStatus(Status::assert((int)$val->status));
            $obj->setAssignee($this->ufac->getUserByID((int)$val->assignee));
            $obj->setCreator($this->ufac->getUserByID((int)$val->created_by));
            $date = new DateTime();
            $obj->setCreateDate($date->setTimestamp(strtotime($val->create_date)));
            $obj->setAssignDate($date->setTimestamp(strtotime($val->assign_date)));
            $ret[] = $obj;
        }
        return $ret;
    }
    
    public function createByUser(User $user): Vector<ScrumElement> {
        $is = new Issue();
        return Vector {$is};
    }
}