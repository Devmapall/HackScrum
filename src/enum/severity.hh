<?hh //strict

enum Severity: int {
    UNKNOWN = -1;
    IDEA = 0;
    NOTICE = 1;
    WARNING = 2;
    CRITICAL = 3;
}

class EnumSeverity {

    public static function fromInt(int $value) :Severity {
        switch($value) {
            case 0: return Severity::IDEA;
                break;
            case 1: return Severity::NOTICE;
                break;
            case 2: return Severity::WARNING;
                break;
            case 3: return Severity::CRITICAL;
                break;
            default: return Severity::UNKNOWN;
                break;
        }
    }
    
    public static function fromString(string $name) :Severity {

        switch($name) {
            case "IDEA": return Severity::IDEA;
                break;
            case "NOTICE": return Severity::NOTICE;
                break;
            case "WARNING": return Severity::WARNING;
                break;
            case "CRITICAL": return Severity::CRITICAL;
                break;
            default: return Severity::UNKNOWN;
        }
    }
}