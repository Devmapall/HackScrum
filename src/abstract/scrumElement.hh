<?hh //strict

require_once ROOT."enum/severity.hh";
require_once ROOT."enum/priority.hh";
require_once ROOT."enum/status.hh";
require_once ROOT."user.hh";

abstract class ScrumElement {

    protected int $ID;
    protected Severity $severity;
    protected Priority $priority;
    protected Status $status;
    protected DateTime $createDate;
    protected DateTime $assignDate;
    protected User $assignee;
    protected Set<string> $history;
    
    public function __construct() {
        $this->ID = -1;
        $this->severity = Severity::UNKNOWN;
        $this->priority = Priority::UNDEFINED;
        $this->status = Status::OPEN;
        $this->createDate = new DateTime();
        $this->assignDate = new DateTime();
        $this->assignee = new User();
        $this->history = new Set(null);
    }
    
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
    
    public function setCreateDate(DateTime $create): void {
        $this->createDate = $create;
    }
    
    public function setAssignDate(DateTime $assign): void {
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
    
    public function getCreateDate(): DateTime {
        return $this->createDate;
    }
    
    public function getAssignDate(): DateTime {
        return $this->assignDate;
    }
    
    public function getHistory(): Set<string> {
        return $this->history;
    }
    
    public function addHistory(string $val): void {
        $this->history->add($val);
    }
}