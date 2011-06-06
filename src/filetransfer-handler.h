/*
 * Copyright (C) 2010, 2011 Daniele E. Domenichelli <daniele.domenichelli@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TELEPATHY_KDE_FILETRANSFER_HANDLER_H
#define TELEPATHY_KDE_FILETRANSFER_HANDLER_H

#include <TelepathyQt4/AbstractClientHandler>
#include <TelepathyQt4/Types>

class KJob;
namespace Tp
{
    class PendingOperation;
}

class FileTransferHandler : public QObject, public Tp::AbstractClientHandler
{
    Q_OBJECT
    Q_DISABLE_COPY(FileTransferHandler);

public:
    FileTransferHandler(QObject* parent = 0);
    virtual ~FileTransferHandler();

    virtual bool bypassApproval() const;
    void handleChannels(const Tp::MethodInvocationContextPtr<> &context,
                        const Tp::AccountPtr &account,
                        const Tp::ConnectionPtr &connection,
                        const QList<Tp::ChannelPtr> &channels,
                        const QList<Tp::ChannelRequestPtr> &requestsSatisfied,
                        const QDateTime &userActionTime,
                        const Tp::AbstractClientHandler::HandlerInfo &handlerInfo);

private Q_SLOTS:
    void onInfoMessage(KJob* job, const QString &plain, const QString &rich);
    void handleResult(KJob* job);


private:
    Tp::ClientRegistrarPtr registrar;
};

#endif // TELEPATHY_KDE_FILETRANSFER_HANDLER_H
