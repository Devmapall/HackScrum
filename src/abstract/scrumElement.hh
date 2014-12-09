<?hh //strict

require_once Config::ROOT."enum/severity.hh";
require_once Config::ROOT."enum/priority.hh";
require_once Config::ROOT."enum/status.hh";
require_once Config::ROOT."user.hh";

abstract class ScrumElement {

    protected int $ID;
    protected string $title;
    protected string $text;
    protected Severity $severity;
    protected Priority $priority;
    protected Status $status;
    protected DateTime $createDate;
    protected DateTime $assignDate;
    protected User $assignee;
    protected Set<string> $history;
    protected User $creator;
    
    public function __construct() {
        $this->ID = -1;
        $this->severity = Severity::IDEA;
        $this->priority = Priority::VERY_LOW;
        $this->status = Status::OPEN;
        $this->createDate = new DateTime("now",DateTimeZone::EUROPE);
        $this->assignDate = new DateTime();
        $this->assignee = new User();
        $this->history = new Set(null);
        $this->creator = new User();
        $this->title = "";
        $this->text = "";
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
    
    public function setCreator(User $creator): void {
        $this->creator = $creator;
    }
    
    public function setTitle(string $title): void {
        $this->title = $title;
    }
    
    public function setText(string $text): void {
        $this->text = $text;
    }
    
    public function getID(): int {
        return $this->ID;
    }
    
    public function getSeverity(): int {
        return $this->severity;
    }
    
    public function getPriority(): int {
        return $this->priority;
    }
    
    public function getStatus(): int {
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
    
    public function getCreator(): User {
        return $this->creator;
    }
    
    public function getTitle(): string {
        return $this->title;
    }
    
    public function getText(): string {
        return $this->text;
    }
    
    public function addHistory(string $val): void {
        $this->history->add($val);
    }
}