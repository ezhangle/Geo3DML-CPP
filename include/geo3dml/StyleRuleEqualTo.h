#pragma once

#include "StyleRule.h"
#include "FieldValue.h"

namespace geo3dml {

	class StyleRuleEqualTo : public StyleRule {
	public:
		/// Constructor.
		/// @param baseValue the value to be compared.
		/// @param onField the field on which a feature's attribute will be used for comparation. Use "gml:id" to represent the ID property of a feature.
		StyleRuleEqualTo(const FieldValue* baseValue, const Field& onField);
		StyleRuleEqualTo(const std::string& fieldName = "", const std::string& valueLiteral = "");
		virtual ~StyleRuleEqualTo();

		void SetFieldName(const std::string& fieldName);
		std::string GetFieldName() const;
		void SetValueLiteral(const std::string& valueLiteral);
		std::string GetValueLiteral() const;

		const Field& GetField() const;
		const FieldValue* GetBaseValue() const;

		virtual bool DoesFeatureMatch(Feature* feature);

	private:
		Field targetField_;
		const FieldValue* baseValue_;
		std::string fieldName_, valueLiteral_;
	};
}
