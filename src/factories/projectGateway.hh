<?hh //strict

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
}
