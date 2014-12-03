<?hh //partial

require_once ROOT."util/AbstractGateway.hh";

abstract class ScrumElementGateway extends AbstractGateway {

    abstract protected function getAll(): Vector<stdClass>;
    abstract protected function getByUser(User $user): Vector<stdClass>;
}