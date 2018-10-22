package org.cocos2dx.cpp;

import com.google.firebase.messaging.RemoteMessage;
import com.google.firebase.messaging.cpp.ListenerService;

public class MyListenerService extends ListenerService {

    @Override
    public void onMessageReceived(RemoteMessage message) {
        super.onMessageReceived(message);
    }

    @Override
    public void onDeletedMessages() {
        super.onDeletedMessages();
    }

    @Override
    public void onMessageSent(String messageId) {
        super.onMessageSent(messageId);
    }

    @Override
    public void onSendError(String messageId, Exception exception) {
        super.onSendError(messageId, exception);
    }
}
