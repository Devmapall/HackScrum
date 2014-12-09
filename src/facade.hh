<?hh //strict

require_once Config::ROOT."factories/userFactory.hh";
require_once Config::ROOT."factories/projectFactory.hh";
require_once Config::ROOT."gateways/issueGateway.hh";
require_once Config::ROOT."enum/severity.hh";
require_once Config::ROOT."enum/priority.hh";
require_once Config::ROOT."issue.hh";

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

        public function getSeverities() :void {
            //UNSAFE
            $names = Severity::getNames();    
            echo "{\"severities\":".json_encode($names)."}";
        }

        public function getPriorities() :void {
            //UNSAFE
            $names = Priority::getNames();
            echo "{\"priorities\":".json_encode($names)."}";
        }

        public function addIssue(string $project, string $severity, string $priority, string $title, string $text) :void {
            //UNSAFE
            $gate = new IssueGateway();
            $pfac = new ProjectFactory();
            $prj = $pfac->getProjectByName($project);
            $sval = Severity::getValues();
            $pval = Priority::getValues();
            $stval = Status::getValues();
            var_dump($sval);
            /*$issue = new Issue();
            $issue->setSeverity($sval[$severity]);
            $issue->setPriority($pval[$priority]);
            $issue->setStatus($stval[$status]);
            $issue->setTitle($title);
            $issue->setText($text);
            $gate->addIssue($issue,$prj->getID(),$prj->getID());*/
        }

        public function addTask(string $project, string $severity, string $priority, string $title, string $text) :void {
            //UNSAFE
            $gate = new TaskGateway();
            $pfac = new ProjectFactory();
            $prj = $pfac->getProjectByName($project);
            $issue = new Task();
            $issue->setProject($prj);
            $issue->setSeverity(Severity::assert($severity));
            $issue->setPriority(Priority::assert($priority));
            $issue->setTitle($title);
            $issue->setText($text);
        }
}
