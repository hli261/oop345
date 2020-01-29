template <typename type>
class pointer {
  type* _thePtr{ nullptr };
public:
  pointer(type* p_ = nullptr) : _thePtr(p_) { }