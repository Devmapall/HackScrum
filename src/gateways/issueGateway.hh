<?hh //partial

require_once Config::ROOT."abstract/scrumElementGateway.hh";

class IssueGateway extends ScrumElementGateway {

    public function __construct() {
        parent::__construct();
    }

    public function getAll(): Vector<stdClass> {
        $sql = "SELECT * FROM issues;";
        $stmt = $this->scrum->query($sql);
        $return = Vector {};
        
        foreach($stmt->fetchObject as $obj) {
            $return[] = $obj;
        }
        
        return $return;
    }
    
    public function getByUser(User $user): Vector<stdClass> {
        $id = $user->getID();
        $sql = "SELECT * FROM issues";
        $stmt = $this->scrum->query($sql);
        $return = Vector {};
        
        foreach($stmt->fetchObject as $obj) {
            $return[] = $obj;
        }
        
        return $return;
    }

    public function addIssue(Issue $issue, int $prj_id) :void {
        //UNSAFE
        $sev = Severity::getValues();
        $pri = Priority::getValues();
        $sta = Status::getValues();
        var_dump($issue->getSeverity());
        $sql = "INSERT INTO issues (title,text,created,project_id,severity,priority,status,assigned,assignee,creator) VALUES 
                ('".$issue->getTitle()."', 
                '".$issue->getText()."', 
                NOW(), 
                ".$prj_id.", 
                ".$issue->getSeverity().", 
                ".$issue->getPriority().", 
                ".$issue->getStatus().", 
                NULL,NULL,".$issue->getCreator()->getID().");";
        $this->scrum->query($sql);
    }
}