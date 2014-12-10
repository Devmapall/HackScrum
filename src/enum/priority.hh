<?hh //strict

enum Priority: int {
    UNKNOWN = -1;
    VERY_LOW = 0;
    LOW = 1;
    MIDDLE = 2;
    HIGH = 3;
    VERY_HIGH = 4;
}

class EnumPriority {

    public static function fromInt(int $value) :Priority {
        switch($value) {
            case 0: return Priority::VERY_LOW;
                break;
            case 1: return Priority::LOW;
                break;
            case 2: return Priority::MIDDLE;
                break;
            case 3: return Priority::HIGH;
                break;
            case 4: return Priority::VERY_HIGH;
                break;
            default: return Priority::UNKNOWN;
        }
    }
    
    public static function fromString(string $name) :Severity {

        switch($name) {
            case "VERY_LOW": return Priority::VERY_LOW;
                break;
            case "LOW": return Priority::LOW;
                break;
            case "MIDDLE": return Priority::MIDDLE;
                break;
            case "HIGH": return Priority::HIGH;
                break;
            case "VERY_HIGH": return Priority::VERY_HIGH;
                break;
            default: return Priority::UNKNOWN;
        }
    }
}