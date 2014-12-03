<?hh //strict

require_once ROOT."abstract/scrumElementGateway.hh";
require_ONCE root."abstract/scrumElement.hh";

abstract class ScrumElementFactory {
    
    protected ScrumElementGateway $gate;

    public function createAll(): Vector<ScrumElement>;
    public function createByUser(User $user): Vector<ScrumElement>;
}