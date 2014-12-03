<?hh //strict

abstract class AbstractGateway {

	protected PDO $auth;
	protected PDO $scrum;

	public function __construct() {
		$this->auth = new PDO("mysql:host=localhost;dbname=auth","root","uUQ8h8LY");
		$this->scrum = new PDO("mysql:host=localhost;dbname=scrum","root","uUQ8h8LY");
	}

}
