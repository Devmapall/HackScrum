<?hh //partial

require_once Config::ROOT."abstract/scrumElementGateway.hh";

class TaskGateway extends ScrumElementGateway {

    public function __construct() {
        parent::__construct();
    }

    public function getAll(): Vector<stdClass> {
        $sql = "SELECT * FROM tasks;";
        $stmt = $this->scrum->query($sql);
        $return = Vector {};
        
        while($obj = $stmt->fetchObject()) {
            $return[] = $obj;
        }
        
        return $return;
    }
    
    public function getByUser(User $user): Vector<stdClass> {
        $id = $user->getID();
        $sql = "SELECT * FROM tasks";
        $stmt = $this->scrum->query($sql);
        $return = Vector {};
        
        foreach($stmt->fetchObject as $obj) {
            $return[] = $obj;
        }
        
        return $return;
    }
    
    public function getUnassigned() :Vector<stdClass> {
        $sql = "SELECT * FROM tasks WHERE assignee is NULL;";
        $stmt = $this->scrum->query($sql);
        $return = Vector{};
        while($row = $stmt->fetchObj()) {
            $return[] = $row;
        }
        return $return;
    }
    
    public function getByID(int $id) {
        $sql = "SELECT * FROM tasks WHERE ID = ".$id.";";
        $stmt = $this->scrum->query($sql);
        $return = Vector{};
        while($row = $stmt->fetchObject()) {
            $return[] = $row;
        }
        return $return;
    }
    
    public function updateTask(Task $task, int $prj_id) :void {
        $sql = "UPDATE task
                    SET 
                        title = '".mysql_real_escape_string($task->getTitle())."',
                        text = '".mysql_real_escape_string($task->getText())."',
                        project_id = ".intval($prj_id).",
                        severity = ".intval($task->getSeverity()).",
                        priority = ".intval($task->getPriority()).",
                        status = ".intval($task->getStatus()).",
                        assignee = ".intval($task->getAssignee()).",
                        assigned = NOW(),
                     WHERE ID = ".intval($task->getID()).";
         $this->scrum->query($sql);                
    }
}