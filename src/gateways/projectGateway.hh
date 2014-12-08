<?hh //partial

require_once "/var/www/hack/scrum/src/util/AbstractGateway.hh";

class ProjectGateway extends AbstractGateway {

	public function __construct() {
		parent::__construct();
	}

	public function addProject(Project $project) :void {
		$title = $project->getTitle();
		$description = $project->getDescription();
		$participants = $project->getParticipants();
		$owner = $project->getOwner();
		$sql = "INSERT INTO projects (name,description,owner_id) VALUES ('".$title."', '".$description."', ".$owner->getID().")";
		$this->scrum->query($sql);
		$id = $this->scrum->lastInsertId();
		foreach($participants as $p) {
			$sql = "INSERT INTO project_user (user_id,project_id) VALUES (".$p->getID().",".$id.")";
			$this->scrum->query($sql);
		}
	}

        public function getByUser(User $u) :Vector<stdClass> {
                var_dump($u);
                $sql = "SELECT * FROM projects WHERE owner_id = ".$u->getID().";";
                $stmt = $this->scrum->query($sql);
                $return = Vector {};
        
                foreach($stmt->fetchObject as $obj) {
                    var_dump($obj);
                    $return[] = $obj;
                }
                var_dump($return);
                return $return;
        }

        public function getParticipants(int $pID) :Vector<stdClass> {
                $sql = "SELECT u.username FROM project_user as pu
                        INNER JOIN user as u ON (pu.user_id = u.id) WHERE project_id = ".$pID.";";
                $stmt = $this->scrum->query($sql);
                $return = Vector {};
        
                foreach($stmt->fetchObject as $obj) {
                    $return[] = $obj;
                }
        
                return $return;
        }
}
