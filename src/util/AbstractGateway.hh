<?hh //strict

abstract class AbstractGateway {

	protected PDO $auth;
	protected PDO $scrum;

	public function __construct() {
		$this->auth = new PDO(AUTHDB_DSN,AUTHDB_USER,AUTHDB_PASS);
		$this->scrum = new PDO(SCRUMDB_DSN,SCRUMDB_USER,SCRUMDB_PASS);
	}

}
