<?hh //strict

require_once Config::ROOT."abstract/scrumElementFactory.hh";
require_once Config::ROOT."gateways/taskGateway.hh";
require_once Config::ROOT."task.hh";

class TaskFactory extends ScrumElementFactory {

    public function __construct() {
        $this->gate = new TaskGateway();
    }
    
    public function createAll(): Vector<ScrumElement> {
        $vec = $this->gate->getAll();
        foreach($vec as $k=>$val) {
            echo $k."=>".$val."\n";
        }
        return Vector{new Task()};
    }
    
    public function createByUser(User $user): Vector<ScrumElement> {
        $t = new Task();
        return Vector {$t};
    }
}