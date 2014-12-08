<?hh //strict

require_once Config::ROOT."abstract/scrumElementGateway.hh";
require_once Config::ROOT."abstract/scrumElement.hh";

abstract class ScrumElementFactory {
    
    protected ScrumElementGateway $gate;

    abstract protected function getAll(): Vector<ScrumElement>;
    abstract protected function getAllByUser(User $user): Vector<ScrumElement>;
    abstract protected function getOpenByUser(User $user): Vector<ScrumElement>;
    abstract protected function getClosedByUser(User $user): Vector<ScrumElement>;
}