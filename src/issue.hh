<?hh //strict

require_once Config::ROOT."abstract/scrumElement.hh";
require_once Config::ROOT."abstract/JSON.hh";

class Issue extends ScrumElement implements JSON {

    public function toJSON() {
        $sev = Severity::getNames();
        $prio = Priority::getNames();
        $stat = Status::getNames();
        
        return  "{  \"ID\":\"".$this->ID."\",
                    \"severity\":\"".$sev[$this->severity]."\",
                    \"priority\":\"".$prio[$this->priority]."\",
                    \"status\":\"".$stat[$this->status]."\",
                    \"createDate\":\"".$this->createDate->format("d.m.Y H:i")."\",
                    \"assignDate\":\"".$this->assignDate->format("d.m.Y H:i")."\",
                    \"assignee\":\"".$this->assignee->getUsername()."\",
                    \"creator\":\"".$this->creator->getUsername()."\",
                    \"title\":\"".$this->title."\",
                    \"text\":\"".$this->text."\"}";
    }
}