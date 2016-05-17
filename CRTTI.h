#paragma once

#define ISKINDOF(classname, pObject) \
	classname::IsKindOf(&classname::ms_RTTI, pObject)
	
class CRTTI
{
public:
	CRTTI(const string& strClassName, const CRTTI* pBaseRTTI)
	{
		m_strClassName = strClassName;
		m_pBaseRTTI = pBaseRTTI;
	}
	
	inline const string& GetClassName() const { return m_strClassName; }
	inline const CRTTI* GetBaseRTTI() const { return m_pBaseRTTI; }
	
private:
	string m_strClassName;
	const CRTTI* m_pBaseRTTI;
}

#define DeclRootRTTI(classname) \
	public: \
		static const CRTTI ms_RTTI; \
		virtual const CRTTI* GetRTTI() const { return &ms_RTTI; }
		static bool IsKindOf(const CRTTI* pRTTI, const classname* pObject) \
		{ \
			if(pObject == NULL) \
			{ \
				return false; \
			} \
		} \
		bool IsKindOf(const CRTTI* pRTTI) const \
		{
			const CRTTI* pTemp = GetRTTI(); \
			if(pTemp) \
			{ \
				if(pTemp == pRTTI) \
				{ \
					return true; \
				} \
			} \
			
			return false; \
		}
		
#define ImplRootRTTI(classname) \
	const CRTTI classname::ms_RTTI(#classname, NULL);
	
#define DeclRTTI \
	public: \
	static const CRTTI ms_RTTI; \
	virtual const CRTTI* GetRTTI() const { return &ms_RTTI; }
	
#define ImpRTTI(classname, baseclassname) \
	const CRTTI classname::ms_RTTI(#classname, NULL)