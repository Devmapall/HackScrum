<?hh //strict

require_once ROOT."abstract/scrumElementFactory.hh";
require_once ROOT."gateways/issueGateway.hh";
require_once ROOT."issue.hh";

class IssueFactory extends ScrumElementFactory {

    public function __construct() {
        parent::__construct();
        $this->gate = new IssueGateway();
    }
    
    public function createAll(): Vector<ScrumElement> {
        $is = new Issue();
        return Vector {$is};
    }
    
    public function createByUser(User $user): Vector<ScrumElement> {
        $is = new Issue();
        return Vector {$is};
    }
}