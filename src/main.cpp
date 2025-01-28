#include <Geode/Geode.hpp>
#include <Geode/modify/CustomSongLayer.hpp>

using namespace geode::prelude;

//If you are reading this, I should warn you: I can't f*cking understand, what is 0x209 offset stands for, but it fixes this download problem if I turn it off.
//I guess it is some multi asset shit, but I am too lazy to find it out.


template <class R, class T>
R& from(T base, intptr_t offset) {
	return *reinterpret_cast<R*>(reinterpret_cast<uintptr_t>(base) + offset);
}


class $modify(CustomSongLayer) {
	void onSearch(CCObject* sender) {
		CustomSongWidget* csw = static_cast<CustomSongWidget*>(this->m_mainLayer->getChildByID("CustomSongWidget"));
		from<bool>(csw, 0x209) = 0;
		static_cast<CCNode*>(csw->getChildByID("buttons-menu")->getChildren()->objectAtIndex(7))->setVisible(0); //why tf this is the only button without a tag????????????
		CustomSongLayer::onSearch(sender);
	}

	void show() {
		this->show();
		CustomSongWidget* csw = static_cast<CustomSongWidget*>(this->m_mainLayer->getChildByID("CustomSongWidget"));
		if (auto lel = GameManager::sharedState()->getEditorLayer()) {
			bool foundSongs = false;
			csw->updateWithMultiAssets(lel->getSongIDs(foundSongs), lel->getSFXIDs(), 0);
		}
	}
};
