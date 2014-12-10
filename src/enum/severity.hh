<?hh //strict

enum Severity: int {
    IDEA = 0;
    NOTICE = 1;
    WARNING = 2;
    CRITICAL = 3;
}

class EnumSeverity {

    public static function fromInt(int $value) :Severity {
        $sev;
        switch($value) {
            case 0: $sev = Severity::IDEA;
                break;
            case 1: $sev = Severity::NOTICE;
                break;
            case 2: $sev = Severity::WARNING;
                break;
            case 3: $sev = Severity::CRITICAL;
                break;
        }
    }
    
    public static function fromString(string $name) :Severity {
        $sev;
        switch($name) {
            case "IDEA": $sev = Severity::IDEA;
                break;
            case "NOTICE": $sev = Severity::NOTICE;
                break;
            case "WARNING": $sev = Severity::WARNING;
                break;
            case "CRITICAL": $sev = Severity::CRITICAL;
                break;
        }
    }
}