<?hh //strict

require_once Config::ROOT."abstract/scrumElementGateway.hh";
require_once Config::ROOT."abstract/scrumElement.hh";

abstract class ScrumElementFactory {
    
    protected ScrumElementGateway $gate;

    abstract protected function createAll(): Vector<ScrumElement>;
    abstract protected function createByUser(User $user): Vector<ScrumElement>;
}