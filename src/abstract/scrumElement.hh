<?hh //strict

require_once ROOT."enum/severity.hh";
require_once ROOT."enum/priority.hh";
require_once ROOT."enum/status.hh";

abstract class ScrumElement {

    protected int $ID;
    protected Severity $severity;
    protected Priority $priority;
    protected Status $status;
    protected Date $createDate;
    protected Date $assignDate;
    protected User $assignee;
    protected Set<string> $history;
    
    public function setID(int $ID): void {
        $this->ID = $ID;
    }
    
    public function setSeverity(Severity $severity): void {
        $this->severity = $severity;
    }
    
    public function setPriority(Priority $priority): void {
        $this->priority = $priority;
    }
    
    public function setStatus(Status $status): void {
        $this->status = $status;
    }
    
    public function setCreateDate(Date $create): void {
        $this->createDate = $create;
    }
    
    public function setAssignDate(Date $assign): void {
        $this->assignDate = $assign;
    }
    
    public function setAssignee(User $assignee): void {
        $this->assignee = $assignee;
    }
    
    public function setHistory(Set<string> $history): void {
        $this->history = $history;
    }
    
    public function getID(): int {
        return $this->ID;
    }
    
    public function getSeverity(): Severity {
        return $this->severity;
    }
    
    public function getPriority(): Priority {
        return $this->priority;
    }
    
    public function getStatus(): Status {
        return $this->status;
    }
    
    public function getCreateDate(): Date {
        return $this->createDate;
    }
    
    public function getAssignDate(): Date {
        return $this->assignDate;
    }
    
    public function getHistory(): Set<string> {
        return $this->history;
    }
    
    public function addHistory(string $val): void {
        $this->history->add($val);
    )
}