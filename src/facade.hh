<?hh //strict

require_once Config::ROOT."factories/userFactory.hh";
require_once Config::ROOT."factories/projectFactory.hh";

class ScrumFacade {

	public function __construct() {}

	public function getUser():void {
		$fac = new UserFactory();
		$user = $fac->getUserBySystem("scrum");
		$stringVector = Vector{};
		foreach($user as $k=>$v) {
			$stringVector[] = $v->getUsername();
		}
		echo "{\"user\":".json_encode($stringVector)."}";
	}

	public function addProject(string $title, string $desc, string $owner, Vector<string> $participants):void {
		$p = new Project();
		$p->setTitle($title);
		$p->setDescription($desc);
		$p->setProjectOwnerByCookie($owner);
		$vec = Vector {};
		$fac = new UserFactory();
		foreach($participants as $pa) {
			$user = $fac->getUserByName($pa);
			$vec[] = $user;
		}

		$p->addParticipants($vec);
		$gate = new ProjectGateway();
		$gate->addProject($p);
	}

        public function getProjects(string $sso) :void {
                $fac = new UserFactory();
                $user = $fac->getUserBySSO($sso);
                $pfac = new ProjectFactory();
                $pvec = $pfac->getProjectsByUser($user);
                $strvec = Vector{};
                foreach($pvec as $k=>$prj) {
                        $strvec[] = $prj->getTitle();
                }
                echo "{\"projects\":".json_encode($strvec)."}";
        }
}
