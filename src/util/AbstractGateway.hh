<?hh //strict

abstract class AbstractGateway {

	protected PDO $auth;
	protected PDO $scrum;

	public function __construct() {
            if(php_sapi_name() == "cli") {
                $this->scrum = new PDO(Config::TESTDB_DSN,Config::TESTDB_USER,Config::TESTDB_PASS);
            } else {
                $this->scrum = new PDO(Config::SCRUMDB_DSN,Config::SCRUMDB_USER,Config::SCRUMDB_PASS);
            }
            
            $this->auth = new PDO(Config::AUTHDB_DSN,Config::AUTHDB_USER,Config::AUTHDB_PASS);
		
	}

}
