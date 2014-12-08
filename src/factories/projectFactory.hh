<?hh //partial

require_once Config::ROOT."project.hh";
require_once Config::ROOT."gateways/projectGateway.hh";
require_once Config::ROOT."factories/userFactory.hh";

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

        public function getProjectsByUser(User $user) :Vector<Project> {
                $vec = $this->gate->getByUser($user);
                $ufac = new UserFactory();
                $ret = Vector{};

                foreach($vec as $val) {
                    $p = new Project();
                    var_dump($vec);
                    $pa = $this->gate->getParticipants((int)$val->ID);
                    $uvec = Vector{};
                    foreach($pa as $u) {
                        $user = $ufac->getUserByName($u->username);
                        $uvec[] = $user;
                    }
                    
                    $p->addParticipants($uvec);
                    $p->setTitle($val->name);
                    $p->setDescription($val->description);
                    $p->setOwnerByID((int)$val->owner);
                    $ret[] = $p;
                }

                return $ret;
        }
}
