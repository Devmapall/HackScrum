<?hh //partial

require_once ROOT."project.hh";
require_once ROOT."gateways/projectGateway.hh";

class ProjectFactory {

	private Vector<Project> $projects;
	private ProjectGateway $gate;

	public function __construct() {
		$this->projects = Vector {};
		$this->gate = new ProjectGateway();
	}

	public function getProjects():Vector<Project> {
		return $this->projects;		
	} 

	private function create() {
		
	}
}
