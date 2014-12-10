<?hh //partial

require_once Config::ROOT."user.hh";
require_once Config::ROOT."gateways/userGateway.hh";

class UserFactory {

	private Vector<User> $userList;
	private UserGateway $gate;

	public function __construct() {
		$this->userList = Vector{};
		$this->gate = new UserGateway();
	}

	public function getUserBySystem(string $system):Vector<User> {
		$vector = $this->gate->getUserBySystem($system);
		$it = $vector->getIterator();
		foreach($it as $key=>$value) {
			if($value instanceof stdClass) {
				$u = new User();
				$u->setUsername($value->username);
				$this->userList->add($u);
			}
		}
		return $this->userList;
	}

	public function getUserBySSO(string $sso) :User {
		$name = $this->gate->getUserBySSO($sso);
		$id = $this->gate->getUserIDByName($name);
		$u = new User();
		$u->setUsername($name);
		$u->setID($id);
		return $u;
	}

	public function getUserByName(string $username) :User {
		$id = $this->gate->getUserIDByName($username);
		$u = new User();
		$u->setUsername($username);
		$u->setID($id);
		return $u;
	}
        
        public function getUserByID(int $id) :User {
		$username = $this->gate->getUserByID($id);
		$u = new User();
                var_dump($id);
                var_dump($username);
		$u->setUsername($username);
		$u->setID($id);
		return $u;
	}
}
