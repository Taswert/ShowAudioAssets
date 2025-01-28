#include <Geode/Geode.hpp>
#include <Geode/modify/CustomSongLayer.hpp>

using namespace geode::prelude;

class $modify(CustomSongLayer) {
	void onSearch(CCObject* sender) {
		CustomSongWidget* csw = static_cast<CustomSongWidget*>(this->m_mainLayer->getChildByID("CustomSongWidget"));
		csw->m_hasSFX = 0;

		//removes this info button on the up-right corner. Also, why tf this is the only button without a tag????????????
		static_cast<CCNode*>(csw->getChildByID("buttons-menu")->getChildren()->objectAtIndex(7))->setVisible(0);
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