<?hh //strict

require_once "IMyPair.hh";

class MyPair<Tv1,Tv2> implements IMyPair {

	private Tv1 $key;
	private Tv2 $val;

	public function __construct(Tv1 $key, Tv2 $val) {
		$this->key = $key;
		$this->val = $val;
	}

	public function getKey():Tv1 {
		return $this->key;
	}

	public function getValue():Tv2 {
		return $this->val;
	}
}
