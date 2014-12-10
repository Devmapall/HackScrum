<?hh //strict

require_once Config::ROOT."abstract/scrumElementFactory.hh";
require_once Config::ROOT."gateways/issueGateway.hh";
require_once Config::ROOT."issue.hh";
require_once Config::ROOT."factories/issueFactory.hh";

class IssueFactory extends ScrumElementFactory {

    public function __construct() {
        $this->gate = new IssueGateway();
    }
    
    public function getAll(): Vector<ScrumElement> {
        $is = new Issue();
        return Vector {$is};
    }
    
    public function getAllByUser(User $user): Vector<ScrumElement> {
        $is = new Issue();
        return Vector {$is};
    }
    
    public function getOpenByUser(User $user): Vector<ScrumElement> {
        $is = new Issue();
        return Vector {$is};
    }
    
    public function getClosedByUser(User $user): Vector<ScrumElement> {
        $is = new Issue();
        return Vector {$is};
    }
    
    public function getUnassigned() :Vector<ScrumElement> {
        $ufac = new UserFactory();
        $data = $this->gate->getUnassigned();
        $vec = Vector{};
        
        foreach($data as $val) {
            $i = new Issue();
            $i->setID((int)$val->ID);
            $i->setSeverity(EnumSeverity::fromInt((int)$val->severity));
            $i->setPriority(EnumPriority::fromInt((int)$val->priority));
            $i->setStatus(EnumStatus::fromInt((int)$val->status));
            $i->setTitle($val->title);
            $i->setText($val->text);
            $i->setCreator($ufac->getUserByID((int)$val->creator));
            $i->setCreateDate(new DateTime($val->create_date));
            $i->setAssignDate(new DateTime($val->assign_date));
            $i->setAssignee($ufac->getUserByID((int)$val->assignee));
            $vec[] = $i;
        }
        
        return $vec;
    }
    
    public function build(string $severity, string $priority, string $title, string $text, User $user) :Issue {
            $issue = new Issue();
            $issue->setSeverity(EnumSeverity::fromString($severity));
            $issue->setPriority(EnumPriority::fromString($priority));
            $issue->setStatus(Status::OPEN);
            $issue->setTitle($title);
            $issue->setText($text);
            $issue->setCreator($user);
            return $issue;
    }
}
