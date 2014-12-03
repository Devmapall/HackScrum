<?hh //strict

class User {

	private int $id;
	private string $username;
	private int $role;

	public function __construct() {
		$this->id = -1;
		$this->username = "";
		$this->role = 0;
	}

	public function setUsername(string $name):void {
		$this->username = $name;
	}

	public function setRole(int $val):void {
		$this->role = $val;
	}

	public function setID(int $id):void {
		$this->id = $id;
	}

	public function getUsername():string { return $this->username; }
	public function getRole():int { return $this->role; }
	public function getID():int { return $this->id; }

}
