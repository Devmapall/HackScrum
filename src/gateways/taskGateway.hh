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
}