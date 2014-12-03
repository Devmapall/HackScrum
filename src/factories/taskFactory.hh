<?hh //strict

require_once ROOT."abstract/scrumElementFactory.hh";
require_once ROOT."gateways/taskGateway.hh";
require_once ROOT."task.hh";

class TaskFactory extends ScrumElementFactory {

    public function __construct() {
        parent::__construct();
        $this->gate = new TaskGateway();
    }
    
    public function createAll(): Vector<ScrumElement> {
        
    }
    
    public function createByUser(User $user): Vector<ScrumElement> {
    
    }
}