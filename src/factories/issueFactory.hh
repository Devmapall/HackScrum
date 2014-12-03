<?hh //strict

require_once ROOT."abstract/scrumElementFactory.hh";
require_once ROOT."gateways/issueGateway.hh";
require_ocne ROOT."issue.hh";

class IssueFactory extends ScrumElementFactory {

    public function __construct() {
        parent::__construct();
        $this->gate = new IssueGateway();
    }
    
    public function createAll(): Vector<Issue> {
        
    }
    
    public function createByUser(User $user): Vector<Issue> {
    
    }
}