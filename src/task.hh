<?hh //strict

require_once Config::ROOT."abstract/scrumElement.hh";

class Task extends ScrumElement {

    public function toJSON() :string {
        return "{}";
    }
}