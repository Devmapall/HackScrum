<?hh //strict

enum Status: int {
    UNKNOWN = -1;
    OPEN = 0;
    ASSIGNED = 1;
    IN_PROGRESS = 2;
    FINISHED = 3;
    CLOSED = 4;
}

class EnumStatus {

    public static function fromInt(int $value) :Status {
        switch($value) {
            case 0: return Status::OPEN;
                break;
            case 1: return Status::ASSIGNED;
                break;
            case 2: return Status::IN_PROGRESS;
                break;
            case 3: return Status::FINISHED;
                break;
            case 4: return Status::CLOSED;
                break;
            default: return Status::UNKNOWN;
                break;
        }
    }
    
    public static function fromString(string $name) :Status {

        switch($name) {
            case "OPEN": return Status::OPEN;
                break;
            case "ASSIGNED": return Status::ASSIGNED;
                break;
            case "IN_PROGRESS": return Status::IN_PROGRESS;
                break;
            case "FINISHED": return Status::FINISHED;
                break;
            case "CLOSED": return Status::CLOSED;
                break;
            default: return Status::UNKNOWN;
        }
    }
}