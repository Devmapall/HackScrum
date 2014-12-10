<?hh //strict

require_once Config::ROOT."abstract/scrumElement.hh";
require_once Config::ROOT."abstract/JSON.hh";

class Issue extends ScrumElement implements JSON {

    public function toJSON() {
        $sev = Severity::getNames();
        $prio = Priority::getNames();
        $stat = Status::getNames();
        
        return "{severity:".$sev[$this->severity].",priority:".$prio[$this->priority]."}";
    }
}