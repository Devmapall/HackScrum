<?hh //strict

abstract class AbstractGateway {

	protected PDO $auth;
	protected PDO $scrum;

	public function __construct() {
		$this->auth = new PDO(Config::AUTHDB_DSN,Config::AUTHDB_USER,Config::AUTHDB_PASS);
		$this->scrum = new PDO(Config::SCRUMDB_DSN,Config::SCRUMDB_USER,Config::SCRUMDB_PASS);
	}

}
