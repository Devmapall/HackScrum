<?hh //strict

require_once ROOT."abstract/scrumElementFactory.hh";
require_once ROOT."gateways/taskGateway.hh";
require_ocne ROOT."task.hh";

class IssueFactory extends ScrumElementFactory {

    public function __construct() {
        parent::__construct();
        $this->gate = new TaskGateway();
    }
    
    public function createAll(): Vector<Task> {
        
    }
    
    public function createByUser(User $user): Vector<Task> {
    
    }
}