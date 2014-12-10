<?hh //partial

require_once Config::ROOT."util/AbstractGateway.hh";

abstract class ScrumElementGateway extends AbstractGateway {

    abstract public function getAll(): Vector<stdClass>;
    abstract public function getByUser(User $user): Vector<stdClass>;
    abstract public function getUnassigned(): Vector<stdClass>;
    abstract public function getByID(): Vector<stdClass>;
}