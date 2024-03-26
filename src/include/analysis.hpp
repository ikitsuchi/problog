#pragma once
#include "derivation.hpp"
#include "probability.hpp"
#include <map>
#include <optional>
#include <vector>

class Analysis {
public:
  const std::vector<Derivation> &get_derivations() const;
  std::optional<Probability>
  get_relation_probability(const Relation &relation) const;
  std::optional<Probability>
  get_rule_probability(const Relation &head,
                       const std::vector<Relation> &body) const;
  void calculate_probability();
  void dump(const std::optional<std::string> &path) const;

public:
  Analysis(const std::string &derivation_path,
           const std::string &probability_path);

private:
  Analysis(const std::vector<Derivation> &derivations,
           const std::map<Relation, Probability> &relation_map,
           const std::map<Rule, Probability> &rule_map)
      : derivations(derivations), relation_map(relation_map),
        rule_map(rule_map){};

private:
  std::vector<Derivation> derivations;
  std::map<Relation, Probability> relation_map;
  std::map<Rule, Probability> rule_map;
};