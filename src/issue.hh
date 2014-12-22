<?hh //strict

require_once Config::ROOT."abstract/scrumElement.hh";
require_once Config::ROOT."abstract/JSON.hh";
require_once Config::ROOT."enum/severity.hh";
require_once Config::ROOT."enum/priority.hh";
require_once Config::ROOT."enum/status.hh";


class Issue extends ScrumElement {

    public function toJSON() :string {
        $sev = Severity::fromInt($this->severity);
        $prio = Priority::fromInt($this->priority);
        $stat = Status::fromInt($this->status);
        $ass = ($this->assignee->getUsername()!=="");
        $assigned = "NO";
        if($ass) {
            $assigned = "YES";
            $assDate = $this->assignDate->format("d.m.Y H:i");
            $assUser = $this->assignee->getUsername();
        } else {
            $assDate = "-";
            $assUser = "-";
        }
        
        return  "{  \"ID\":\"".$this->ID."\",
                    \"severity\":\"".$sev[$this->severity]."\",
                    \"priority\":\"".$prio[$this->priority]."\",
                    \"status\":\"".$stat[$this->status]."\",
                    \"createDate\":\"".$this->createDate->format("d.m.Y H:i")."\",
                    \"assignDate\":\"".$assDate."\",
                    \"assignee\":\"".$assUser."\",
                    \"creator\":\"".$this->creator->getUsername()."\",
                    \"title\":\"".$this->title."\",
                    \"assigned\":\"".$assigned."\",
                    \"text\":\"".$this->text."\",
                    \"Type\":\"Issue\"}";
    }
}