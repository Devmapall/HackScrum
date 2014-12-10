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
        $t = new Task;
        return Vector{$t};
    }
}