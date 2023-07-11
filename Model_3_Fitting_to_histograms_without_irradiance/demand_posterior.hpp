
// Code generated by stanc v2.29.0
#include <stan/model/model_header.hpp>
namespace demand_posterior_model_namespace {

using stan::model::model_base_crtp;
using namespace stan::math;


stan::math::profile_map profiles__;
static constexpr std::array<const char*, 29> locations_array__ = 
{" (found before start of program)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 9, column 4 to column 16)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 10, column 4 to column 16)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 11, column 4 to column 17)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 12, column 4 to column 15)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 13, column 4 to column 15)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 30, column 4 to column 25)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 32, column 8 to column 33)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 33, column 8 to column 127)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 31, column 19 to line 34, column 5)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 31, column 4 to line 34, column 5)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 17, column 4 to column 29)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 18, column 4 to column 29)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 19, column 4 to column 34)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 20, column 4 to column 29)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 21, column 4 to column 30)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 23, column 8 to column 33)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 24, column 8 to column 131)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 25, column 8 to column 146)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 22, column 19 to line 26, column 5)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 22, column 4 to line 26, column 5)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 2, column 4 to column 19)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 3, column 10 to column 11)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 3, column 4 to column 47)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 4, column 10 to column 11)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 4, column 4 to column 41)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 5, column 10 to column 11)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 5, column 4 to column 33)",
 " (in '/home/ProjektDataAnalytics/Model_2_Fitting_to_histograms/demand_posterior.stan', line 30, column 10 to column 11)"};




class demand_posterior_model final : public model_base_crtp<demand_posterior_model> {

 private:
  int N;
  std::vector<int> day_of_week;
  std::vector<int> hour;
  std::vector<double> demand_samples; 
  
 
 public:
  ~demand_posterior_model() { }
  
  inline std::string model_name() const final { return "demand_posterior_model"; }

  inline std::vector<std::string> model_compile_info() const noexcept {
    return std::vector<std::string>{"stanc_version = stanc3 v2.29.0", "stancflags = "};
  }
  
  
  demand_posterior_model(stan::io::var_context& context__,
                         unsigned int random_seed__ = 0,
                         std::ostream* pstream__ = nullptr) : model_base_crtp(0) {
    int current_statement__ = 0;
    using local_scalar_t__ = double ;
    boost::ecuyer1988 base_rng__ = 
        stan::services::util::create_rng(random_seed__, 0);
    (void) base_rng__;  // suppress unused var warning
    static constexpr const char* function__ = "demand_posterior_model_namespace::demand_posterior_model";
    (void) function__;  // suppress unused var warning
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    (void) DUMMY_VAR__;  // suppress unused var warning
    try {
      int pos__ = std::numeric_limits<int>::min();
      pos__ = 1;
      current_statement__ = 21;
      context__.validate_dims("data initialization","N","int",
           std::vector<size_t>{});
      N = std::numeric_limits<int>::min();
      
      
      current_statement__ = 21;
      N = context__.vals_i("N")[(1 - 1)];
      current_statement__ = 21;
      stan::math::check_greater_or_equal(function__, "N", N, 0);
      current_statement__ = 22;
      stan::math::validate_non_negative_index("day_of_week", "N", N);
      current_statement__ = 23;
      context__.validate_dims("data initialization","day_of_week","int",
           std::vector<size_t>{static_cast<size_t>(N)});
      day_of_week = std::vector<int>(N, std::numeric_limits<int>::min());
      
      
      current_statement__ = 23;
      day_of_week = context__.vals_i("day_of_week");
      current_statement__ = 23;
      stan::math::check_greater_or_equal(function__, "day_of_week",
                                            day_of_week, 0);
      current_statement__ = 23;
      stan::math::check_less_or_equal(function__, "day_of_week", day_of_week,
                                         6);
      current_statement__ = 24;
      stan::math::validate_non_negative_index("hour", "N", N);
      current_statement__ = 25;
      context__.validate_dims("data initialization","hour","int",
           std::vector<size_t>{static_cast<size_t>(N)});
      hour = std::vector<int>(N, std::numeric_limits<int>::min());
      
      
      current_statement__ = 25;
      hour = context__.vals_i("hour");
      current_statement__ = 25;
      stan::math::check_greater_or_equal(function__, "hour", hour, 1);
      current_statement__ = 25;
      stan::math::check_less_or_equal(function__, "hour", hour, 24);
      current_statement__ = 26;
      stan::math::validate_non_negative_index("demand_samples", "N", N);
      current_statement__ = 27;
      context__.validate_dims("data initialization","demand_samples",
          "double", std::vector<size_t>{static_cast<size_t>(N)});
      demand_samples = 
        std::vector<double>(N, std::numeric_limits<double>::quiet_NaN());
      
      
      current_statement__ = 27;
      demand_samples = context__.vals_r("demand_samples");
      current_statement__ = 28;
      stan::math::validate_non_negative_index("demand", "N", N);
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
    }
    num_params_r__ = 1 + 1 + 1 + 1 + 1;
    
  }
  
  template <bool propto__, bool jacobian__ , typename VecR, typename VecI, 
  stan::require_vector_like_t<VecR>* = nullptr, 
  stan::require_vector_like_vt<std::is_integral, VecI>* = nullptr> 
  inline stan::scalar_type_t<VecR> log_prob_impl(VecR& params_r__,
                                                 VecI& params_i__,
                                                 std::ostream* pstream__ = nullptr) const {
    using T__ = stan::scalar_type_t<VecR>;
    using local_scalar_t__ = T__;
    T__ lp__(0.0);
    stan::math::accumulator<T__> lp_accum__;
    stan::io::deserializer<local_scalar_t__> in__(params_r__, params_i__);
    int current_statement__ = 0;
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    (void) DUMMY_VAR__;  // suppress unused var warning
    static constexpr const char* function__ = "demand_posterior_model_namespace::log_prob";
    (void) function__;  // suppress unused var warning
    
    try {
      local_scalar_t__ a_hour = DUMMY_VAR__;
      current_statement__ = 1;
      a_hour = in__.template read<local_scalar_t__>();
      local_scalar_t__ b_hour = DUMMY_VAR__;
      current_statement__ = 2;
      b_hour = in__.template read<local_scalar_t__>();
      local_scalar_t__ offset_ = DUMMY_VAR__;
      current_statement__ = 3;
      offset_ = in__.template read<local_scalar_t__>();
      local_scalar_t__ a_day = DUMMY_VAR__;
      current_statement__ = 4;
      a_day = in__.template read<local_scalar_t__>();
      local_scalar_t__ b_day = DUMMY_VAR__;
      current_statement__ = 5;
      b_day = in__.template read<local_scalar_t__>();
      {
        current_statement__ = 11;
        lp_accum__.add(stan::math::normal_lpdf<propto__>(a_hour, -32, 10));
        current_statement__ = 12;
        lp_accum__.add(stan::math::normal_lpdf<propto__>(b_hour, 980, 10));
        current_statement__ = 13;
        lp_accum__.add(
          stan::math::normal_lpdf<propto__>(offset_, 14500, 2000));
        current_statement__ = 14;
        lp_accum__.add(stan::math::normal_lpdf<propto__>(a_day, -300, 20));
        current_statement__ = 15;
        lp_accum__.add(stan::math::normal_lpdf<propto__>(b_day, 1200, 100));
        current_statement__ = 20;
        for (int i = 1; i <= N; ++i) {
          int day = std::numeric_limits<int>::min();
          current_statement__ = 16;
          day = stan::model::rvalue(day_of_week, "day_of_week",
                  stan::model::index_uni(i));
          current_statement__ = 17;
          lp_accum__.add(
            stan::math::normal_lpdf<propto__>(
              stan::model::rvalue(demand_samples, "demand_samples",
                stan::model::index_uni(i)),
              (((((a_hour *
                    stan::math::pow(
                      stan::model::rvalue(hour, "hour",
                        stan::model::index_uni(i)), 2)) +
                   (b_hour *
                     stan::model::rvalue(hour, "hour",
                       stan::model::index_uni(i)))) +
                  (a_day * stan::math::pow(day, 2))) + (b_day * day)) +
                offset_), 100));
          current_statement__ = 18;
          lp_accum__.add(
            stan::math::normal_lpdf<false>(
              stan::model::rvalue(demand_samples, "demand_samples",
                stan::model::index_uni(i)),
              (((((a_hour *
                    stan::math::pow(
                      stan::model::rvalue(hour, "hour",
                        stan::model::index_uni(i)), 2)) +
                   (b_hour *
                     stan::model::rvalue(hour, "hour",
                       stan::model::index_uni(i)))) +
                  (a_day * stan::math::pow(day, 2))) + (b_day * day)) +
                offset_), 100));
        }
      }
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
    }
    lp_accum__.add(lp__);
    return lp_accum__.sum();
    } // log_prob_impl() 
    
  template <typename RNG, typename VecR, typename VecI, typename VecVar, 
  stan::require_vector_like_vt<std::is_floating_point, VecR>* = nullptr, 
  stan::require_vector_like_vt<std::is_integral, VecI>* = nullptr, 
  stan::require_std_vector_vt<std::is_floating_point, VecVar>* = nullptr> 
  inline void write_array_impl(RNG& base_rng__, VecR& params_r__,
                               VecI& params_i__, VecVar& vars__,
                               const bool emit_transformed_parameters__ = true,
                               const bool emit_generated_quantities__ = true,
                               std::ostream* pstream__ = nullptr) const {
    using local_scalar_t__ = double;
    stan::io::deserializer<local_scalar_t__> in__(params_r__, params_i__);
    stan::io::serializer<local_scalar_t__> out__(vars__);
    static constexpr bool propto__ = true;
    (void) propto__;
    double lp__ = 0.0;
    (void) lp__;  // dummy to suppress unused var warning
    int current_statement__ = 0; 
    stan::math::accumulator<double> lp_accum__;
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    constexpr bool jacobian__ = false;
    (void) DUMMY_VAR__;  // suppress unused var warning
    static constexpr const char* function__ = "demand_posterior_model_namespace::write_array";
    (void) function__;  // suppress unused var warning
    
    try {
      double a_hour = std::numeric_limits<double>::quiet_NaN();
      current_statement__ = 1;
      a_hour = in__.template read<local_scalar_t__>();
      double b_hour = std::numeric_limits<double>::quiet_NaN();
      current_statement__ = 2;
      b_hour = in__.template read<local_scalar_t__>();
      double offset_ = std::numeric_limits<double>::quiet_NaN();
      current_statement__ = 3;
      offset_ = in__.template read<local_scalar_t__>();
      double a_day = std::numeric_limits<double>::quiet_NaN();
      current_statement__ = 4;
      a_day = in__.template read<local_scalar_t__>();
      double b_day = std::numeric_limits<double>::quiet_NaN();
      current_statement__ = 5;
      b_day = in__.template read<local_scalar_t__>();
      out__.write(a_hour);
      out__.write(b_hour);
      out__.write(offset_);
      out__.write(a_day);
      out__.write(b_day);
      if (stan::math::logical_negation((stan::math::primitive_value(
            emit_transformed_parameters__) || stan::math::primitive_value(
            emit_generated_quantities__)))) {
        return ;
      } 
      if (stan::math::logical_negation(emit_generated_quantities__)) {
        return ;
      } 
      std::vector<double> demand =
         std::vector<double>(N, std::numeric_limits<double>::quiet_NaN());
      current_statement__ = 10;
      for (int i = 1; i <= N; ++i) {
        int day = std::numeric_limits<int>::min();
        current_statement__ = 7;
        day = stan::model::rvalue(day_of_week, "day_of_week",
                stan::model::index_uni(i));
        current_statement__ = 8;
        stan::model::assign(demand,
          stan::math::normal_rng(
            (((((a_hour *
                  stan::math::pow(
                    stan::model::rvalue(hour, "hour",
                      stan::model::index_uni(i)), 2)) +
                 (b_hour *
                   stan::model::rvalue(hour, "hour",
                     stan::model::index_uni(i)))) +
                (a_day * stan::math::pow(day, 2))) + (b_day * day)) +
              offset_), 100, base_rng__),
          "assigning variable demand", stan::model::index_uni(i));
      }
      out__.write(demand);
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
    }
    } // write_array_impl() 
    
  template <typename VecVar, typename VecI, 
  stan::require_std_vector_t<VecVar>* = nullptr, 
  stan::require_vector_like_vt<std::is_integral, VecI>* = nullptr> 
  inline void transform_inits_impl(VecVar& params_r__, VecI& params_i__,
                                   VecVar& vars__,
                                   std::ostream* pstream__ = nullptr) const {
    using local_scalar_t__ = double;
    stan::io::deserializer<local_scalar_t__> in__(params_r__, params_i__);
    stan::io::serializer<local_scalar_t__> out__(vars__);
    int current_statement__ = 0;
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    
    try {
      int pos__ = std::numeric_limits<int>::min();
      pos__ = 1;
      local_scalar_t__ a_hour = DUMMY_VAR__;
      a_hour = in__.read<local_scalar_t__>();
      out__.write(a_hour);
      local_scalar_t__ b_hour = DUMMY_VAR__;
      b_hour = in__.read<local_scalar_t__>();
      out__.write(b_hour);
      local_scalar_t__ offset_ = DUMMY_VAR__;
      offset_ = in__.read<local_scalar_t__>();
      out__.write(offset_);
      local_scalar_t__ a_day = DUMMY_VAR__;
      a_day = in__.read<local_scalar_t__>();
      out__.write(a_day);
      local_scalar_t__ b_day = DUMMY_VAR__;
      b_day = in__.read<local_scalar_t__>();
      out__.write(b_day);
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
    }
    } // transform_inits_impl() 
    
  inline void get_param_names(std::vector<std::string>& names__) const {
    
    names__ = std::vector<std::string>{"a_hour", "b_hour", "offset_",
      "a_day", "b_day", "demand"};
    
    } // get_param_names() 
    
  inline void get_dims(std::vector<std::vector<size_t>>& dimss__) const {
    
    dimss__ = std::vector<std::vector<size_t>>{std::vector<size_t>{},
      std::vector<size_t>{}, std::vector<size_t>{}, std::vector<size_t>{
      }, std::vector<size_t>{}, std::vector<size_t>{static_cast<size_t>(N)}};
    
    } // get_dims() 
    
  inline void constrained_param_names(
                                      std::vector<std::string>& param_names__,
                                      bool emit_transformed_parameters__ = true,
                                      bool emit_generated_quantities__ = true) const
    final {
    
    param_names__.emplace_back(std::string() + "a_hour");
    param_names__.emplace_back(std::string() + "b_hour");
    param_names__.emplace_back(std::string() + "offset_");
    param_names__.emplace_back(std::string() + "a_day");
    param_names__.emplace_back(std::string() + "b_day");
    if (emit_transformed_parameters__) {
      
    }
    
    if (emit_generated_quantities__) {
      for (int sym1__ = 1; sym1__ <= N; ++sym1__) {
        {
          param_names__.emplace_back(std::string() + "demand" + '.' + std::to_string(sym1__));
        } 
      }
    }
    
    } // constrained_param_names() 
    
  inline void unconstrained_param_names(
                                        std::vector<std::string>& param_names__,
                                        bool emit_transformed_parameters__ = true,
                                        bool emit_generated_quantities__ = true) const
    final {
    
    param_names__.emplace_back(std::string() + "a_hour");
    param_names__.emplace_back(std::string() + "b_hour");
    param_names__.emplace_back(std::string() + "offset_");
    param_names__.emplace_back(std::string() + "a_day");
    param_names__.emplace_back(std::string() + "b_day");
    if (emit_transformed_parameters__) {
      
    }
    
    if (emit_generated_quantities__) {
      for (int sym1__ = 1; sym1__ <= N; ++sym1__) {
        {
          param_names__.emplace_back(std::string() + "demand" + '.' + std::to_string(sym1__));
        } 
      }
    }
    
    } // unconstrained_param_names() 
    
  inline std::string get_constrained_sizedtypes() const {
    
    return std::string("[{\"name\":\"a_hour\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"b_hour\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"offset_\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"a_day\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"b_day\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"demand\",\"type\":{\"name\":\"array\",\"length\":" + std::to_string(N) + ",\"element_type\":{\"name\":\"real\"}},\"block\":\"generated_quantities\"}]");
    
    } // get_constrained_sizedtypes() 
    
  inline std::string get_unconstrained_sizedtypes() const {
    
    return std::string("[{\"name\":\"a_hour\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"b_hour\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"offset_\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"a_day\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"b_day\",\"type\":{\"name\":\"real\"},\"block\":\"parameters\"},{\"name\":\"demand\",\"type\":{\"name\":\"array\",\"length\":" + std::to_string(N) + ",\"element_type\":{\"name\":\"real\"}},\"block\":\"generated_quantities\"}]");
    
    } // get_unconstrained_sizedtypes() 
    
  
    // Begin method overload boilerplate
    template <typename RNG>
    inline void write_array(RNG& base_rng,
                            Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                            Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                            const bool emit_transformed_parameters = true,
                            const bool emit_generated_quantities = true,
                            std::ostream* pstream = nullptr) const {
      const size_t num_params__ = 
  ((((1 + 1) + 1) + 1) + 1);
      const size_t num_transformed = 0;
      const size_t num_gen_quantities = N;
      std::vector<double> vars_vec(num_params__
       + (emit_transformed_parameters * num_transformed)
       + (emit_generated_quantities * num_gen_quantities));
      std::vector<int> params_i;
      write_array_impl(base_rng, params_r, params_i, vars_vec,
          emit_transformed_parameters, emit_generated_quantities, pstream);
      vars = Eigen::Map<Eigen::Matrix<double,Eigen::Dynamic,1>>(
        vars_vec.data(), vars_vec.size());
    }

    template <typename RNG>
    inline void write_array(RNG& base_rng, std::vector<double>& params_r,
                            std::vector<int>& params_i,
                            std::vector<double>& vars,
                            bool emit_transformed_parameters = true,
                            bool emit_generated_quantities = true,
                            std::ostream* pstream = nullptr) const {
      const size_t num_params__ = 
  ((((1 + 1) + 1) + 1) + 1);
      const size_t num_transformed = 0;
      const size_t num_gen_quantities = N;
      vars.resize(num_params__
        + (emit_transformed_parameters * num_transformed)
        + (emit_generated_quantities * num_gen_quantities));
      write_array_impl(base_rng, params_r, params_i, vars, emit_transformed_parameters, emit_generated_quantities, pstream);
    }

    template <bool propto__, bool jacobian__, typename T_>
    inline T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
                       std::ostream* pstream = nullptr) const {
      Eigen::Matrix<int, -1, 1> params_i;
      return log_prob_impl<propto__, jacobian__>(params_r, params_i, pstream);
    }

    template <bool propto__, bool jacobian__, typename T__>
    inline T__ log_prob(std::vector<T__>& params_r,
                        std::vector<int>& params_i,
                        std::ostream* pstream = nullptr) const {
      return log_prob_impl<propto__, jacobian__>(params_r, params_i, pstream);
    }


    inline void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream = nullptr) const final {
      std::vector<double> params_r_vec(params_r.size());
      std::vector<int> params_i;
      transform_inits(context, params_i, params_r_vec, pstream);
      params_r = Eigen::Map<Eigen::Matrix<double,Eigen::Dynamic,1>>(
        params_r_vec.data(), params_r_vec.size());
    }

  inline void transform_inits(const stan::io::var_context& context,
                              std::vector<int>& params_i,
                              std::vector<double>& vars,
                              std::ostream* pstream__ = nullptr) const {
     constexpr std::array<const char*, 5> names__{"a_hour", "b_hour",
      "offset_", "a_day", "b_day"};
      const std::array<Eigen::Index, 5> constrain_param_sizes__{1, 1, 
       1, 1, 1};
      const auto num_constrained_params__ = std::accumulate(
        constrain_param_sizes__.begin(), constrain_param_sizes__.end(), 0);
    
     std::vector<double> params_r_flat__(num_constrained_params__);
     Eigen::Index size_iter__ = 0;
     Eigen::Index flat_iter__ = 0;
     for (auto&& param_name__ : names__) {
       const auto param_vec__ = context.vals_r(param_name__);
       for (Eigen::Index i = 0; i < constrain_param_sizes__[size_iter__]; ++i) {
         params_r_flat__[flat_iter__] = param_vec__[i];
         ++flat_iter__;
       }
       ++size_iter__;
     }
     vars.resize(num_params_r__);
     transform_inits_impl(params_r_flat__, params_i, vars, pstream__);
    } // transform_inits() 
    
};
}
using stan_model = demand_posterior_model_namespace::demand_posterior_model;

#ifndef USING_R

// Boilerplate
stan::model::model_base& new_model(
        stan::io::var_context& data_context,
        unsigned int seed,
        std::ostream* msg_stream) {
  stan_model* m = new stan_model(data_context, seed, msg_stream);
  return *m;
}

stan::math::profile_map& get_stan_profile_data() {
  return demand_posterior_model_namespace::profiles__;
}

#endif


