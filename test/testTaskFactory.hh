<?hh //partial

class TestTaskFactory extends TestCase {

	private TaskFactory $fac;
        private ScrumElement $t;

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
            $vec = $this->fac->getAll();
            $this->t = $vec[0];
        }
}
