<?hh //strict

require_once Config::ROOT."abstract/scrumElementFactory.hh";
require_once Config::ROOT."gateways/issueGateway.hh";
require_once Config::ROOT."issue.hh";

class IssueFactory extends ScrumElementFactory {

    public function __construct() {
        parent::__construct();
        $this->gate = new IssueGateway();
    }
    
    public function getAll(): Vector<ScrumElement> {
        $is = new Issue();
        return Vector {$is};
    }
    
    public function getAllByUser(User $user): Vector<ScrumElement> {
        $is = new Issue();
        return Vector {$is};
    }
    
    public function getOpenByUser(User $user): Vector<ScrumElement> {
        $is = new Issue();
        return Vector {$is};
    }
    
    public function getClosedByUser(User $user): Vector<ScrumElement> {
        $is = new Issue();
        return Vector {$is};
    }
}