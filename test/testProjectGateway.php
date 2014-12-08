<?hh //partial

class TestProjectGateway extends TestCase {

	private ProjectGateway $gate;

        public function __construct() {
            parent::__construct();
            $this->gate = new ProjectGateway();
        }

        public function setUp() :void {
            parent::reset();
            $this->gate = new ProjectGateway();
        }

        public function tearDown() :void {
            $this->gate = new ProjectGateway();
        }

	public function testgetProjectsByUser() {
            $vec = $this->gate->getAll();
            var_dump($vec);
        }
}