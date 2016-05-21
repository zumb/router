<?hh //strict
namespace Zumb\Routing;

class Router
{
  const string RESOURCE_PATTERN = "/\/([^\/]+)(?:\/([^\/]+))?/";

  protected string $target = '';

  protected array<string> $parameters = [];

  protected array<string> $segments = [];

  public function load(string $uri):void
  {
    $matches = [];
    if(preg_match_all(self::RESOURCE_PATTERN, $uri, $matches)) {
      $this->segments = array_map($segment ==> ucfirst($segment), $matches[1]);
      $this->target = implode("\\", $this->segments);
      $this->parameters = array_filter($matches[2]);
    }
  }

  public function getTarget():string
  {
    return $this->target;
  }

  public function getParameters():array<string>
  {
    return $this->parameters;
  }

  public function isResource():bool
  {
    return count($this->segments) == count($this->parameters);
  }
}
