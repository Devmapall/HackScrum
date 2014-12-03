<?hh //partial

class TestTaskFactory extends TestCase {

	private TaskFactory $fac;
        private Task $t;

        public function __construct() {
            parent::__construct();
            $this->fac = new TaskFactory();
            $this->t = new Task();
        }

        public function setUp() :void {
            parent::reset();
            $this->fac = new TaskFactory();
            $this->t = new Task();
        }

        public function tearDown() :void {
            $this->fac = new TaskFactory();
            $this->t = new Task();
        }

	public function testCreateAll() {
            $vec = $this->fac->createAll();
            $this->t = $vec[0];
            var_dump($this->t);
            
        }
}
