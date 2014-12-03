<?hh //strict

require_once ROOT."util/AbstractGateway.hh";

abstract class ScrumElementGateway extends AbstractGateway {

    protected function getAll(): Vector<stdClass>;
    protected function getByUser(User $user): Vectot<stdClass>;
}