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
    
    public function getUnassigned() :Vector<stdClass> {
        $sql = "SELECT * FROM issues WHERE assignee is NULL;";
        $stmt = $this->scrum->query($sql);
        $return = Vector{};
        while($row = $stmt->fetchObject()) {
            $return[] = $row;
        }
        return $return;
    }

    public function addIssue(Issue $issue, int $prj_id) :void {
        //UNSAFE
        var_dump($issue);
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

    public function updateIssue(Issue $issue, int $prj_id) :void {
        $sql = "UPDATE issues
                    SET 
                        title = '".mysql_real_escape_string($issue->getTitle())."',
                        text = '".mysql_real_escape_string($issue->getText())."',
                        project_id = ".intval($prj_id).",
                        severity = ".intval($issue->getSeverity()).",
                        priority = ".intval($issue->getPriority()).",
                        status = ".intval($issue->getStatus()).",
                        assignee = ".intval($issue->getAssignee()).",
                        assigned = NOW(),
                     WHERE ID = ".intval($issue->getID()).";
         $this->scrum->query($sql);                
    }
    
    public function getByID(int $id) {
        $sql = "SELECT * FROM issues WHERE ID = ".$id.";";
        $stmt = $this->scrum->query($sql);
        $return = Vector{};
        while($row = $stmt->fetchObject()) {
            $return[] = $row;
        }
        return $return;
    }
}