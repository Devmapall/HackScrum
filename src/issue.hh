<?hh //strict

require_once Config::ROOT."abstract/scrumElement.hh";
require_once Config::ROOT."abstract/JSON.hh";

class Issue extends ScrumElement implements JSON {

    public function toJSON() {
        $sev = Severity::getNames();
        $prio = Priority::getNames();
        $stat = Status::getNames();
        $ass = ($this->assignee->getUsername()!=="");
        $assigned = "No";
        if($ass) {
            $assigned = "YES";
            $assDate = $this->assignDate->format("d.m.Y H:i");
        } else {
            $assDate = "-";
        }
        
        return  "\"issue\":{  \"ID\":\"".$this->ID."\",
                    \"severity\":\"".$sev[$this->severity]."\",
                    \"priority\":\"".$prio[$this->priority]."\",
                    \"status\":\"".$stat[$this->status]."\",
                    \"createDate\":\"".$this->createDate->format("d.m.Y H:i")."\",
                    \"assignDate\":\"".$assDate."\",
                    \"assignee\":\"".$this->assignee->getUsername()."\",
                    \"creator\":\"".$this->creator->getUsername()."\",
                    \"title\":\"".$this->title."\",
                    \"assigned\":\"".$assigned."\",
                    \"text\":\"".$this->text."\",
                    \"Type\":\"Issue\"}";
    }
}