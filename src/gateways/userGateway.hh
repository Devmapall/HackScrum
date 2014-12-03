<?hh //strict

require_once "/var/www/hack/scrum/src/util/AbstractGateway.hh";

class UserGateway extends AbstractGateway {

	public function __construct() {
		parent::__construct();
	}

	public function getUserBySystem(string $system):Vector<string> {
		$vector = Vector {};
		$stmt = $this->auth->query("SELECT u.username 
FROM systems as s 
INNER JOIN user_systems as us ON (s.ID = us.system_id) 
INNER JOIN user as u ON (us.user_id = u.ID) 
WHERE s.ID = 3;");
		for($i=0;$i<$stmt->rowCount();$i++) {
			$vector[] = $stmt->fetchObject();
		}
		return $vector;
	}

	public function getUserBySSO(string $sso):string {
		$stmt = $this->auth->query("select u.username FROM auth.sessions as s INNER JOIN auth.user as u ON (s.user_id = u.ID) WHERE s.ID = '".$sso."';"); 
		$name = $stmt->fetchObject()->username;
		return $name;
	}

	public function getUserIDByName(string $name):int {
		$stmt = $this->auth->query("select id from auth.user where username = '".$name."';");
		return (int)$stmt->fetchObject()->id;
	}
        
        public function getUserByID(int $id):string {
		$stmt = $this->auth->query("select username from auth.user where id = '".$id."';");
		return (string)$stmt->fetchObject()->username;
	}
}
